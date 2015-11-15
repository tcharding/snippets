#!/usr/bin/perl -w
use strict;

# clear an array
@array = ();

# print number of elements
my @array = qw( one two three );
print "Array contains ", scalar @array, "elements\n";

# print array using x operator
my @items = qw( one two three );
my $format = "The items are:\n" . ("%10s\n"   x @items), @items;

my %last_name = (
    Tobin => 'Harding',
    Milla => 'Harding',
    Tom => 'Jones'
);
my @keys = keys %last_name;
my @values = values %last_name;

while ( ($key, $value) = each %hash ) {
    print "$key => $value\n";
}

if (exists $hash{key}) {
    # hash contains value for key
}

# remove item from hash
delete $hash{key};
