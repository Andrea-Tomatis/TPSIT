'''
RNA transcription: Given a DNA strand, return its RNA complement.

@Andrea-Tomatis
'''

def transcript(dna):
    dna2rna = {'G':'C', 'C':'G', 'T':'A', 'A':'U'}
    return ''.join(dna2rna[nucleotide] for nucleotide in dna.upper())

def main():
    print(transcript('aacgt'))

if __name__ == '__main__':
    main()