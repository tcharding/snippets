#!/usr/bin/perl -w
use strict;

$^I = "";

while (<>) {
    s/\s+/ /g;
    print;
    print "\n";
}

