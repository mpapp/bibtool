#!/bin/perl -W
# =============================================================================
#  
#  This file is part of BibTool.
#  It is distributed under the GNU General Public License.
#  See the file COPYING for details.
#  
#  (c) 2011-2015 Gerd Neugebauer
#  
#  Net: gene@gerd-neugebauer.de
#  
#*=============================================================================

=head1 NAME

macro_file.t - Test suite for BibTool macro.file.

=head1 SYNOPSIS

macro_file.t 

=head1 DESCRIPTION

This module contains some test cases. Running this module as program
will run all test cases and print a summary for each. Optionally files
*.out and *.err are left if the expected result does not match the
actual result.

=head1 OPTIONS

none

=head1 AUTHOR

Gerd Neugebauer

=cut

use strict;
use BUnit;


#------------------------------------------------------------------------------
BUnit::run(name         => 'macro_file_1',
	   args         => '--macro.file{-} -o _null.out bib/xampl.bib',
	   expected_out => <<__EOF__,
\@STRING{acm	= "The OX Association for Computing Machinery" }
\@STRING{stoc	= " Symposium on the Theory of Computing" }
\@STRING{stoc-key= "OX{\\singleletter{stoc}}" }
__EOF__
    expected_err => <<__EOF__,

*** BibTool WARNING:  (line 29 in ./bib/xampl.bib): 125 non-space characters ignored.
__EOF__
   check => sub {unlink('_null.out'); return 0;}
    );

#------------------------------------------------------------------------------
BUnit::run(name         => '_m_1',
	   args         => '-m - -o _null.out bib/xampl.bib',
	   expected_out => <<__EOF__,
\@STRING{acm	= "The OX Association for Computing Machinery" }
\@STRING{stoc	= " Symposium on the Theory of Computing" }
\@STRING{stoc-key= "OX{\\singleletter{stoc}}" }
__EOF__
    expected_err => <<__EOF__,

*** BibTool WARNING:  (line 29 in ./bib/xampl.bib): 125 non-space characters ignored.
__EOF__
   check => sub {unlink('_null.out'); return 0;}
    );

#------------------------------------------------------------------------------
# Local Variables: 
# mode: perl
# End: 
