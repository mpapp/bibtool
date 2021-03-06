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

print_comma_at_end.t - Test suite for BibTool print.comma.at.end.

=head1 SYNOPSIS

print_comma_at_end.t 

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
BUnit::run(name         => 'print_comma_at_end_1',
	   args         => '-- print.comma.at.end=on bib/x1.bib',
	   expected_out => <<__EOF__,

\@Manual{	  bibtool,
  title		= {BibTool},
  author	= {Gerd Neugebauer},
  year		= 2015
}
__EOF__
    expected_err => ''
    );

#------------------------------------------------------------------------------
BUnit::run(name         => 'print_comma_at_end_2',
	   args         => '-- print.comma.at.end=off bib/x1.bib',
	   expected_out => <<__EOF__,

\@Manual{	  bibtool
  ,title	= {BibTool}
  ,author	= {Gerd Neugebauer}
  ,year		= 2015
}
__EOF__
    expected_err => ''
    );

#------------------------------------------------------------------------------
# Local Variables: 
# mode: perl
# End: 
