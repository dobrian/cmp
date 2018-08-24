# Sound File Formats

---

Sound data is stored in a variety of file formats. Some file formats store the sound in a very straightforward way, simply as a list of sample values, without any elaborate data compression encoding. Other file formats store the data in an encoded form that yields a smaller file size. The encoded formats are quite varied in terms of their data compression methods. We'll mention a few of them here, but in general we won't engage in detailed discussion of them. For the purposes of this lesson, we'll focus on uncompressed sound files.

Some programming environments, such as the [Web Audio API](WebAudio API) and [Max][Cycling74 Max], already provide ways to open sound files and use the sound data, and they also provide ways to write some of these standard file formats. So, you might never need to write a program from scratch to manage every low-level aspect of opening and managing and writing sound files. On the other hand, some day you might. And in any case, it's probably good to have some idea of what's going on under the hood.

The two most common uncompressed file formats are Audio Interchange File Format, a.k.a. AIFF (.aif), and Waveform Audio File Format, a.k.a. WAVE (.wav). AIFF was invented by Apple, and WAVE was invented by Microsoft and IBM. So, conventionally AIFF is used in Mac OS, and WAVE is used in Windows. But really, almost all applications in both operating systems can read and save either of those two file formats with no problems. And the two formats are really not very different from each other.

---

## AIFF

Two excellent resources for learning the structure of an AIFF file are:
- [Audio File Formats][audio file formats], by Paul Bourke
- [AIFF/AIFC Sound File Specifications][aiff-aifc spec], by Peter Kabal

The first of those two documents explains the file format and gives examples of how you might handle file headers and "chunks" using data structures in your program. It also contains example C code showing how you might write an AIFF file to disk. Even if you're not fluent in the C language, by reading the chunk descriptions you can get an idea of how different parts of an AIFF file are organized. At the bottom of the document, the author describes the  ways in which a WAVE file differs from an AIFF file, and provides example C code for writing a WAVE file.

The second website amplifies that document in an important way. A couple years after the publication of the AIFF standard, the standard was modified to include the capability to contain various compressed data formats in addition to the uncompressed PCM-sampled data format of the original AIFF standard. Thus, a file type of AIFC was established to extend the AIFF specification. This document shows what changes that entailed, and provides links to all the most important official documentation of those standards.

The very first thing you encounter in an AIFF file is a header consisting of four characters (four bytes) 'FORM', followed by an unsigned long integer telling the total size in bytes of the rest of the file (after the size info), followed by four more characters 'AIFF' (or 'AIFC'). In a WAVE file, the four characters 'FORM' are replaced by 'RIFF', and the four characters 'AIFF' (or 'AIFC') are replaced by 'WAVE'. Your program can open the file and "sniff" those first twelve bytes of the header to see what kind of file it is and how big it is.

After that, there is usually a chunk with the ID 'COMM' (for "common") in AIFF/AIFC or ID 'fmt ' (for "format") in WAVE, containing vital information about the sound data, such as its format, its sampling rate, the number of channels, and the number of sample frames. Then there will be a 'SSND' chunk that contains the actual sample data. There are several other possible chunk types, but those three we've mentioned&mdash;header (container), common, and data&mdash;are the required ones.

## MP3

MP3 (.mp3) has been the most ubiquitous file format for compressed audio interchange on the Web. It uses knowledge about psychoacoustics to determine what aspects of a sound might be dispensable because we don't generally notice them, throws some of that "redundant" information away, and uses data compression techniques to further reduce the sound of the file. Because some information is lost in this compression process, it is known as "lossy" compression, which implies a degradation of quality compared with uncompressed PCM-sampled data. The question of how objectionable this degradation is is subjective and context-dependent; it involves a trade-off between file size (and thus speed of transmission and copying) and quality of information. Within the MP3 specification, there are different levels of quality available, depending on the amount of compression desired.

Here is a tutorial on the basic principles of MP3 encoding/decoding.
- [MP3 Learning Object][MP3 Tutorial], by Nathaniel Tull Phillips

The technology to enact MP3 encoding and decoding is patent-free. The Web Audio API and Max both have this decoding capability built in, thus they provide ways to open and decompress MP3 files, as do most end-user commercial audio applications, including open-source applications such as [Audacity][Audacity], which uses the open-source [LAME][LAME] encoding engine.

## Other

There are many other compression methods, too numerous to try to list entirely. At the time of this writing, one of the most noteworthy methods is Advanced Audio Coding (AAC), which is very similar to MP3 but is thought to be more efficient and of better sound quality. That form of compression is usually contained in a .m4a file type.

There are some lossless compression methods that provide some space savings, but are generally less commonly used than the uncompressed lossless AIFF and WAVE formats or the lossy compressed formats MP3 and AAC. The most common of those are the Free Lossless Audio Codec (FLAC), and an Apple-supported counterpart, Apple Lossless Audio Compression (ALAC).

---

## Terminology

- AIFF
- WAVE
- MP3
- AAC
- compression
- uncompressed
- header
- chunk
- sample frame
- ckID

---

## Self-Study

To ensure you really understand the AIFF (or WAVE) file structure, if you feel confident in your ability to program in a language such as C, Java, or Python, you could try implementing a simple sound file reading and writing program. The official AIFF specification document contains a chart showing an example file structure, and the Bourke article provides a file-writing code example in C.

For example, you could write a program that simply sniffs the beginning of a file and reports whether it's a sound file, and if so, what file format it is, and some details about its audio contents, such as its sampling rate, number of channels, data format, duration (in seconds and in sample frames), and file size.

---

## Self-Quiz

What are the two most common file formats for uncompressed audio?
<br>AIFF (.aif) and WAVE (.wav)

What are the two most common file formats for compressed audio?
<br>MP3 (.mp3) and AAC (.m4a)

In an (unncompressed) audio file, where is the sample rate stored?
<br>In the common chunk ('COMM' in AIFF) or format chunk ('fmt ' in WAVE)

What bytes are not included in the file's internal size report?
<br>The four bytes of the file ckID ('FORM' or 'RIFF'), and the four bytes of the size report itself

How would you determine the duration of a sound in an AIFF or WAVE file?
<br>Use the report of the number of sample frames in the data chunk, and divide that by the sample rate reported in the common (or format) chunk.

---

## Additional Resources

[Audio File Formats](audio file formats), Paul Bourke

[AIFF/AIFC Sound File Specifications](aiff-aifc spec), Peter Kabal

[MP3 Learning Object][MP3 Tutorial], Nathaniel Tull Phillips

[audio file formats]:[http://paulbourke.net/dataformats/audio/]
[aiff-aifc spec]:[http://www-mmsp.ece.mcgill.ca/Documents/AudioFormats/AIFF/AIFF.html]
[Cycling74 Max]:[https://cycling74.com/products/max]
[WebAudio API]:[https://www.w3.org/TR/webaudio/]
[MP3 Tutorial]:[http://music.arts.uci.edu/dobrian/MP3Tutorial/]
[Audacity]:[https://www.audacityteam.org/]
[LAME]:[http://lame.sourceforge.net/index.php]
