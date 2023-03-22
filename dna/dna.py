import csv
import sys
from sys import argv
from cs50 import get_string
def main():

    # TODO: Check for command-line usage
   if len(argv) != 3:
       print('Error occured')
       exit(1)
    # TODO: Read database file into a variable
csv_file = open(argv[1], 'r')

strands = []
persons = {}
for ind, row in enumerate(csv_file):
    if ind == 0:
        strands = [strand for strand in row.strip().split(',')][1:]
    else:
        curr_row = row.strip().split(',')
        persons[curr_row[0]] = [int(x) for x in curr_row[1:]]

dna_strand = open(argv[2], 'r').read()
final_strands = []
for strand in strands:
    i = 0
    max_strand = -1
    cur_max = 0
    while i < len(dna_strand):
        cur_window = dna_strand[i:i+len(strand)]
        if cur_window == strand:
            cur_max += 1
            max_strand = max(max_strand, cur_max)
            i += len(strand)
        else:
            cur_max = 0
            i += 1
    final_strands.append(max_strand)

for name,data in persons.items():
    if data == final_strands:
        print(name)
        exit(0)

print('no match')
    # TODO: Read DNA sequence file into a variable

    # TODO: Find longest match of each STR in DNA sequence

    # TODO: Check database for matching profiles




def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
