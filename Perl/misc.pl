# Miscellaneous Perl Snippets

# subroutine arguments
sub {
    my ($var) = @_;
    # ...
}

    

# usage
die "Usage: $0 <file> \n"
    if (@ARGV == 0);
    
