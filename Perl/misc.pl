# Miscellaneous Perl Snippets

# IO
chomp (@lines = <STDIN>);	# read all lines, removing newline, into @lines

# read in whole file
my $file = "foo.txt";
open my $fh, '<', $file or die "Cannot open $file";
my $contents = do { local( $/ ) ; <$fh> } ;

# read in file with key value pairs
my $text = read_file( $file ) ;
my %config = $test =~ /^(\w+)=(.+)$/mg ;

 # usage
die "Usage: $0 <file> \n"
    if (@ARGV == 0);
    

# replace string in file
$ perl -pi.bak -e 's/blue/red/g' *.pl
