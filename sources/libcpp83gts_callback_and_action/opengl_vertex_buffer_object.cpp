#include <iostream>	/* std::cout */
#include <sstream>	/* std::ostringstream */
#include <cmath>	/* sin(-) cos(-) */

#define GLEW_STATIC	/* use glew32s.lib */
#include <GL/glew.h>	/* gl.hより前に必要 */

#include "calc_rad_deg.h"
#include "calc_trace_by_hsv.h"
#include "opengl_vertex_buffer_object.h"

/*---------- opengl::vertex_buffer_object関数 ----------*/

namespace opengl {

vertex_buffer_object::vertex_buffer_object()
	:id_vbo_(0)
	,pixel_size_(0)
	/* vboメモリで浮動小数の型 vbo_floatと合わせること*/
	//,vbo_type_(GL_DOUBLE)
	,vbo_type_(GL_FLOAT)
	,hsv_view_start_sw_(false)
{
}
vertex_buffer_object::~vertex_buffer_object()
{
	this->close();
}
std::string vertex_buffer_object::open_or_reopen( unsigned pixel_size )
{
	/* 以前のvboバッファが残っていれば閉じる */
	this->close();

	/* vboバッファのIDを得る。座標と色をまとめて一つで */
	glGenBuffers( 1 ,&(this->id_vbo_) );

	/* 処理対象指定 */
	glBindBuffer( GL_ARRAY_BUFFER ,this->id_vbo_ );

	/* 頂点用と色用のVBOを同時に確保 */
	const GLsizeiptr glsize = pixel_size * sizeof(vertex_color);
	glBufferData( GL_ARRAY_BUFFER ,glsize ,nullptr ,GL_DYNAMIC_DRAW );

	/* 頂点用と色用のVBO確保の確認 */
	GLint chk_sz=0;
	glGetBufferParameteriv( GL_ARRAY_BUFFER ,GL_BUFFER_SIZE ,&chk_sz );
	if ( glsize != chk_sz ) {

		/* バッファオブジェクトを破棄する */
		if (0 < chk_sz) {
			glDeleteBuffers( 1 , &(this->id_vbo_) );
		}

		/* bindを指定なしにする */
		glBindBuffer( GL_ARRAY_BUFFER ,0 );

		this->id_vbo_ = 0;

		std::ostringstream ost;
		ost	<< "Error:Can not get vbo for vertex:"
			<< "pixel_size("
			<<  pixel_size
			<< ")*sizeof(vertex_color)("
			<<    sizeof(vertex_color)
			<< ")!=chk_sz("
			<<       chk_sz
			<< ")"
			;
		return ost.str();
	}

	/* 確保した数を記憶 */
	this->pixel_size_ = pixel_size;

	/* bindを指定なしにする */
	glBindBuffer( GL_ARRAY_BUFFER ,0 );

	return std::string();
}
void vertex_buffer_object::close(void)
{
	/* VBO用ID破棄 */
	if (this->id_vbo_ != 0) {
		glDeleteBuffers( 1 , &(this->id_vbo_) );
		this->id_vbo_ = 0;
	}
}

vertex_buffer_object::vertex_color* vertex_buffer_object::start_vertex_color( void )
{
	if (this->id_vbo_ == 0) { return nullptr; }
	/* 頂点用VBO */
	glBindBuffer( GL_ARRAY_BUFFER ,this->id_vbo_ );
	return static_cast<vertex_color *>(glMapBuffer(
				GL_ARRAY_BUFFER , GL_READ_WRITE ));
	/* ここからend_vertex_color()までbufferがbind状態 */
}
void vertex_buffer_object::end_vertex_color( void )
{
	if (this->id_vbo_ == 0) { return; }
	glUnmapBuffer( GL_ARRAY_BUFFER );
}

void vertex_buffer_object::draw(void)
{
	if (this->id_vbo_ == 0) {
		return;
	}
	/* 頂点,色 の格納場所を伝える */
	glBindBuffer( GL_ARRAY_BUFFER ,this->id_vbo_ );
	glVertexPointer( 3 ,this->vbo_type_ ,sizeof(vertex_color)
			,static_cast<GLubyte *>(nullptr) );
	glColorPointer( 3 ,GL_UNSIGNED_BYTE ,sizeof(vertex_color)
			,static_cast<GLubyte *>(nullptr)+sizeof(vertex) );

	/* 描画を有効化 */
	glEnableClientState( GL_VERTEX_ARRAY );
	glEnableClientState( GL_COLOR_ARRAY );

	/* 描画 */
	glDrawArrays( GL_POINTS ,0 ,this->pixel_size_ );

	/* 描画を無効化 */
	glDisableClientState( GL_COLOR_ARRAY );
	glDisableClientState( GL_VERTEX_ARRAY );

	/* bind指定なしにする。エラー除け??? */
	glBindBuffer( GL_ARRAY_BUFFER ,0 );
}

void vertex_buffer_object::pr_vbo_info(void)
{
	std::cout << "      vertex size="
		<< this->pixel_size_ * sizeof(vertex) << "bytes\n";
	std::cout << "       color size="
		<< this->pixel_size_ * sizeof(color) << "bytes\n";
	std::cout << "vertex_color size="
		<< this->pixel_size_ * sizeof(vertex_color) << "bytes\n";
}

void vertex_buffer_object::hsv_to_xyz(
	const double h , const double s , const double v
	,double& x , double& y , double& z
)
{
	/* hsv --> x,y,z */
	x = cos( calc::rad_from_deg(h) ) * s * v;
	y = sin( calc::rad_from_deg(h) ) * s * v;
	z = 1. - v;
}

void vertex_buffer_object::hsv_to_xyzarray(
	const double h , const double s , const double v
	, vertex_buffer_object::vertex& xyz
)
{
	/* hsv --> xyzarray */
	xyz.x = static_cast<vertex_buffer_object::vbo_float>(
		cos( calc::rad_from_deg(h) ) * s * v
	);
	xyz.y = static_cast<vertex_buffer_object::vbo_float>(
		sin( calc::rad_from_deg(h) ) * s * v
	);
	xyz.z = static_cast<vertex_buffer_object::vbo_float>(
		1. - v
	);
}
} // namespace opengl
