/* ================================================================= */
/* =========== LANSA FOR WINDOWS GLOBAL DEFINITIONS ================ */
/* ================================================================= */
/*                                                                   */
/* Source File         : X_GLOUSR.H                                  */
/* OS/Dependencies     : No                                          */
/* End User Modifiable : Yes                                         */
/* Description         : LANSA User Definable Global Definitions     */
/*                                                                   */
/* ================================================================= */

#ifndef __INCL_X_GLOUSR_H__
#define __INCL_X_GLOUSR_H__

#define X_DBM_VARCHAR_LEN          50
#define X_DBM_VARBINARY_LEN        50
#define X_MAX_SQL_STATEMENT        4000

#if (defined X_OPERATING_SYSTEM_WIN)
#define X_ERROR_LOG                "X_ERR.LOG"
#define X_LANSA_BASE_DIR           "\\X_LANSA\\"
#define X_LANSA_EXECUTE_SUBDIR     "execute"
#elif defined(X_OPERATING_SYSTEM_UNIX)
#define X_ERROR_LOG                "x_err.log"
#define X_LANSA_BASE_DIR           "/x_lansa/"
#define X_LANSA_EXECUTE_SUBDIR     "bin"
#endif
#define X_LANSA_SOURCE_SUBDIR      "source"
#define X_LANSA_OBJECT_SUBDIR      "object"
#define X_LANSA_EXPORT_SUBDIR      "export"

#if defined(X_OPERATING_SYSTEM_UNIX)
#define X_LANSA_ROOT               "/lansa"
#endif

#if defined(X_OPERATING_SYSTEM_WIN32) && defined(X_OS_32BIT)
#define X_LANSA_ROOT               "C:\\X_WIN95"
#endif

#if defined(X_OPERATING_SYSTEM_WIN32) && defined(X_OS_64BIT)
#define X_LANSA_ROOT               "C:\\X_WIN64"
#endif

#define X_STND_EDIT_CODE           'L'

#if defined(X_OPERATING_SYSTEM_WIN)
#define X_DEFAULT_PRINTER_PORT     "LPT1"
#endif

#if defined(X_OPERATING_SYSTEM_UNIX)
#if defined(X_OPERATING_SYSTEM_ISERIES)
#define X_DEFAULT_PRINTER_PORT     "*JOBD"
#else
#define X_DEFAULT_PRINTER_PORT     "*PATH"
#endif
#endif

#define X_MAXIMUM_PRINT_LINE_WIDTH 500

#define X_DEFAULT_VISIBLE_SCROLL_ITEMS 15

/* Defines the initial options for displaying normal and         */
/* emphasised text                                               */

#define X_NORM_TEXT_ATTRIBUTES   "NNNNN"
#define X_NORM_TEXT_COLOUR       'B'
#define X_EMPH_TEXT_ATTRIBUTES   "NNNNN"
#define X_EMPH_TEXT_COLOUR       'R'

/* Other standard / default display attributes                   */

#define X_DEFAULT_INPUT_COLOUR             'G'
#define X_DEFAULT_OUTPUT_COLOUR            'G'
#define X_DEFAULT_INPUT_ATTRIBUTES         "NNNNNNNNNNNNNNNN"
#define X_DEFAULT_OUTPUT_ATTRIBUTES        "NNNNNNNNNNNNNNNN"

#define X_PBIN_INPUT_COLOUR                'G'
#define X_PBIN_OUTPUT_COLOUR               'G'
#define X_PBIN_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBIN_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBFP_INPUT_COLOUR                'W'
#define X_PBFP_OUTPUT_COLOUR               'W'
#define X_PBFP_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBFP_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBBR_INPUT_COLOUR                'G'
#define X_PBBR_OUTPUT_COLOUR               'G'
#define X_PBBR_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBBR_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBCM_INPUT_COLOUR                'B'
#define X_PBCM_OUTPUT_COLOUR               'B'
#define X_PBCM_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBCM_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBGH_INPUT_COLOUR                'B'
#define X_PBGH_OUTPUT_COLOUR               'B'
#define X_PBGH_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBGH_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBNT_INPUT_COLOUR                'G'
#define X_PBNT_OUTPUT_COLOUR               'G'
#define X_PBNT_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBNT_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBET_INPUT_COLOUR                'W'
#define X_PBET_OUTPUT_COLOUR               'W'
#define X_PBET_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBET_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBEN_INPUT_COLOUR                'G'
#define X_PBEN_OUTPUT_COLOUR               'G'
#define X_PBEN_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBEN_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBEE_INPUT_COLOUR                'W'
#define X_PBEE_OUTPUT_COLOUR               'W'
#define X_PBEE_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBEE_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBCN_INPUT_COLOUR                'G'
#define X_PBCN_OUTPUT_COLOUR               'G'
#define X_PBCN_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBCN_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBCE_INPUT_COLOUR                'W'
#define X_PBCE_OUTPUT_COLOUR               'W'
#define X_PBCE_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBCE_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#define X_PBSI_INPUT_COLOUR                'W'
#define X_PBSI_OUTPUT_COLOUR               'G'
#define X_PBSI_INPUT_ATTRIBUTES            "NNNNNNNNNNNNNNNN"
#define X_PBSI_OUTPUT_ATTRIBUTES           "NNNNNNNNNNNNNNNN"

#ifdef X_OPERATING_SYSTEM_UNIX

#define X_HELP_BLINKING_COLOUR             "red-bR"
#define X_HELP_NORMAL_BACKGROUND_COLOUR    "white-W"
#define X_HELP_NORMAL_FOREGROUND_COLOUR    "black-K"
#define X_HELP_HI_INTENSITY_FONT           "-adobe-new century schoolbook-bold-i-normal--12-120-75-75-p-76-iso8859-1"
#define X_HELP_BLINKING                    "b"
#define X_HELP_UNDERLINE                   "u"
#define X_HELP_REVERSE_VIDEO               "r"
#define X_HELP_HI_INTENSITY                "h"

#endif

#endif /* !def __INCL_X_GLOUSR_H__ */
