#!/usr/bin/perl
use strict;
use warnings;
use feature qw/say/;

# clear an array
@array = ();

# print number of elements
my @array = qw( one two three );
print "Array contains ", scalar @array, "elements\n";

# print array using x operator
my @items = qw( one two three );
my $format = "The items are:\n" . ("%10s\n"   x @items), @items;
