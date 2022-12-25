#include "lwip/apps/fs.h"
#include "lwip/def.h"

#define file_NULL (struct fsdata_file *) NULL

#ifndef FS_FILE_FLAGS_HEADER_INCLUDED
#define FS_FILE_FLAGS_HEADER_INCLUDED 1
#endif
#ifndef FS_FILE_FLAGS_HEADER_PERSISTENT
#define FS_FILE_FLAGS_HEADER_PERSISTENT 0
#endif

/* FSDATA_FILE_ALIGNMENT: 0=off, 1=by variable, 2=by include */
#ifndef FSDATA_FILE_ALIGNMENT
#define FSDATA_FILE_ALIGNMENT 0
#endif
#ifndef FSDATA_ALIGN_PRE
#define FSDATA_ALIGN_PRE
#endif
#ifndef FSDATA_ALIGN_POST
#define FSDATA_ALIGN_POST
#endif
#if FSDATA_FILE_ALIGNMENT==2
#include "fsdata_alignment.h"
#endif
#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__img_sics_gif = 0;
#endif

const unsigned char homepage_name[] = "/homepage.html";
const unsigned char board_info_name[] = "/board_info.html";
const unsigned char f407board_img_name[] = "/atstartf407_with_ethernet.jpg";
const unsigned char favicon_name[] = "/favicon.ico";

extern const HTTP_FILE FileTab[];

struct fsdata_file file_board_info_html[] = { {
		file_NULL,
board_info_name,
0,
0,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_HEADER_PERSISTENT,
}};

struct fsdata_file file_homepage_html[] = { {
file_board_info_html,
homepage_name,
0,
0,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_HEADER_PERSISTENT,
}};

struct fsdata_file file_board_jpg[] = { {
file_homepage_html,
f407board_img_name,
0,
0,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_HEADER_PERSISTENT,
}};

struct fsdata_file file_favicon_ico_html[] = { {
		file_board_jpg,
		favicon_name,
		0,
		0,
FS_FILE_FLAGS_HEADER_INCLUDED | FS_FILE_FLAGS_HEADER_PERSISTENT,
}};

#define FS_ROOT file_favicon_ico_html
#define FS_NUMFILES 4
