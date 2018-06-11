![](images/ikmb_bfx_logo.png)

# In silico fragmentation of long sequencing reads

# Please note

This software reads long reads in fastq format (e.g. PacBio) and performs *in silico* random fragmentation. The reads will be random fragmented to the size chosen by parameter (-l/--length). All fragments originating from the same long read will be tagged as paired/linked in the fastq header. Random fragmentation starts at a random nucleotide at the 5' end of the read. The random start nucleotide can be any between 0 and (-l/--length).

This software uses [TCLAP](https://github.com/eile/tclap) for argument parsing which comes with its own licence. 


## Installing the tool

To install this pipeline, simply clone the repository to a location:

`git clone https://github.com/MiWitt/FragmentLongReads.git`

Move to the project directory:

`cd FragmentLongReads`

Initialize the submodules:

`git submodule init`

And update the submodules:

`git submodule update`

To compile the tool run make after running a clean (got issues from the sub modules when not cleaning before):

`make`

To update the code, run git update inside of the local clone:

`git update`

## Usage

   ./fragmentLongReads  -f <string> [-l <unsigned int>] [--] [--version]
                        [-h]

Where: 

   -f <string>,  --FASTQ <string>
     (required)  The UNPACKED fastq file

   -l <unsigned int>,  --length <unsigned int>
     length of the in silico fragments

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.


   FragmentLongReads:

   Provide a fastq file containing long reads. The reads will be in silico
   random fragmented to the size chosen by parameter (-l/--length). All
   fragments originating from the same long read will be tagged as
   paired/linked in the fastq header. Random fragmentation starts at a
   random nucleotide at the 5' end of the read. The random start nucleotide
   can be any between 0 and (-l/--length). 


## Output

The output goes to stdout.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


