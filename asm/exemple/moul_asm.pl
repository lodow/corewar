
#!/usr/bin/perl

use strict;

sub main()
{
    if (scalar(@ARGV) != 3)
    {
	print "Usage : ./moul_asm.pl <Src_REP> <Of_ASM_bin> <Your_ASM_bin>\n";
    }
    else
    {
	my @src_files = qx{ls $ARGV[0]};
	system("mkdir tmp");
	system("cp -r $ARGV[0] tmp_of/");
	system("cp -r $ARGV[0] tmp_your/");
	print "Generating Bin Files...\n";
	foreach my $file (@src_files) {
	    system("./$ARGV[1] tmp_of/$file");
	    system("./$ARGV[2] tmp_your/$file");
	}
	print "Testing files...\n";
	foreach my $file (@src_files) {
	    chop($file);
	    chop($file);
	    $file = $file . "cor";
	    my @result = qx{diff tmp_of/$file tmp_your/$file};
	    if (@result){
		print "$file : KO\n";
	    }
	}
	system("rm -rf tmp_of tmp_your");
    }
}

main();



