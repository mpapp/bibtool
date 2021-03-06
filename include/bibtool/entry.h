/*** entry.h ******************************************************************
** 
** This file is part of BibTool.
** It is distributed under the GNU General Public License.
** See the file COPYING for details.
** 
** (c) 1996-2015 Gerd Neugebauer
** 
** Net: gene@gerd-neugebauer.de
** 
**-----------------------------------------------------------------------------
** Description:
**	
**
**	This module provides also access to the functions and
**	variables defined in |entry.c|. Consult also the documentation
**	of this file for details.
**
**	This header file automatically includes |symbols.h|.
**
******************************************************************************/

#include <bibtool/type.h>

/*-----------------------------------------------------------------------------
** Variable:	entry_type
** Type:	Uchar **
** Purpose:	This is an array of strings which represent entry
**		types. They are either built-in or user defined. Use
**		the function |def_entry_type()| to allocate a new
**		entry type and the function |get_entry_type()| to find
**		a certain entry type.
**___________________________________________________			     */
 extern Uchar **entry_type;

/*-----------------------------------------------------------------------------
** Macro:	EntryName()
** Type:	Uchar *
** Purpose:	This is the functional representation of the name
**		component for an entry type. The argument is the index
**		of an entry type. This macro can also be used as
**		lvalue. No range checks are performed. 
** Arguments:
**	Entry	Index of the entry.
**___________________________________________________			     */
#define EntryName(Entry)  entry_type[Entry]

/*-----------------------------------------------------------------------------
** Constant:	BIB_EOF
** Type:	int
** Purpose:	This symbolic constant is returned when a record has
**		to be read and the end of file has been
**		encountered. It is some negative value for which no
**		entry type is defined.
**___________________________________________________			     */
#define BIB_EOF		-2

/*-----------------------------------------------------------------------------
** Constant:	BIB_NOOP
** Type:	int
** Purpose:	This symbolic constant is returned when a record has
**		to be read and something has been encountered which
**		should be ignored. It is some negative value for which no
**		entry type is defined.
**___________________________________________________			     */
#define BIB_NOOP	-1

/*-----------------------------------------------------------------------------
** Constant:	BIB_STRING
** Type:	int
** Purpose:	This symbolic constant representing a record type of a
**		\BibTeX{} macro (|@String|). This is a special record
**		type which is provided automatically.
**___________________________________________________			     */
#define BIB_STRING	0

/*-----------------------------------------------------------------------------
** Constant:	BIB_PREAMBLE
** Type:	int
** Purpose:	This symbolic constant representing a record type of a
**		\BibTeX{} preamble (|@Preamble|). This is a special record
**		type which is provided automatically.
**___________________________________________________			     */
#define BIB_PREAMBLE	1

/*-----------------------------------------------------------------------------
** Constant:	BIB_COMMENT
** Type:	int
** Purpose:	This symbolic constant representing a record type of a
**		\BibTeX{} comment (|@Comment|). This is a special record
**		type which is provided automatically.
**___________________________________________________			     */
#define BIB_COMMENT	2

/*-----------------------------------------------------------------------------
** Constant:	BIB_ALIAS
** Type:	int
** Purpose:	This symbolic constant representing a record type of a
**		\BibTeX{} alias (|@Alias|) which is proposed for
**		\BibTeX\,1.0. This is a special record type which is
**		provided automatically.
**___________________________________________________			     */
#define BIB_ALIAS	3

/*-----------------------------------------------------------------------------
** Constant:	BIB_MODIFY
** Type:	int
** Purpose:	This symbolic constant representing a record type of a
**		\BibTeX{} modification rule (|@Modify|) which is proposed for
**		\BibTeX\,1.0. This is a special record type which is
**		provided automatically.
**___________________________________________________			     */
#define BIB_MODIFY	4

/*-----------------------------------------------------------------------------
** Constant:	BIB_INCLUDE
** Type:	int
** Purpose:	This symbolic constant representing a record type of a
**		\BibTeX{} inclusion instruction (|@Include|) which is
**		proposed for \BibTeX\,1.0. This is a special record
**		type which is provided automatically
**___________________________________________________			     */
#define BIB_INCLUDE	5

/*-----------------------------------------------------------------------------
** Macro:	IsSpecialRecord()
** Purpose:	Test whether a given record type denotes a special record.
**		Special records are those defined above. They are
**		provided automatically since \BibTeX{} is supposed to
**		do so as well.
** Arguments:
**	Type	Record type which should be checked.
** Returns:	|TRUE| iff the rcord type denoted a special record.
**___________________________________________________			     */
#define IsSpecialRecord(Type) ( Type <= 5 )

/*-----------------------------------------------------------------------------
** Macro:	IsNormalRecord()
** Purpose:	Test whether a given record is a normal record. A
**		normal record is one defined by a user. Normal records
**		have indices larger than those of special records.
** Arguments:
**	Type	Record type which should be checked.
** Returns:	|TRUE| iff the rcord type denoted a normal record.
**___________________________________________________			     */
#define IsNormalRecord(Type)  ( Type > 5 )


#ifdef __STDC__
#define _ARG(A) A
#else
#define _ARG(A) ()
#endif
 Uchar * get_entry_type _ARG((int i));		   /* entry.c                */
 int find_entry_type _ARG((Uchar *s));		   /* entry.c                */
 void def_entry_type _ARG((Uchar * s));		   /* entry.c                */
 void init_entries _ARG((void));		   /* entry.c                */
