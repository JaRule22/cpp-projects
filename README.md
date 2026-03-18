# Authorship Detection Part 1

This is my first C++ Lab Project in College, here are the instructions for this lab:


Preface

This lab is based on Learn By Doing 12.20 Exercise 2 and a famous “nifty assignment” on authorship detection(The block quotes minus the text in square brackets are drawn from that assignment).   In this part of the lab, you will compute three statistics on pieces of text extracted from a single prepared file and print them.  This is the first part of software pipeline to solve the authorship detection problem.  

“Automated authorship detection is the process of using a computer program to analyze a large collection of texts, one of which has an unknown author, and making guesses about the author of that unattributed text. The basic idea is to use different statistics from the text -- called "features" in the machine learning community -- to form a linguistic "signature" for each text. One example of a simple feature is the number of words per sentence. Some authors may prefer short sentences while others tend to write sentences that go on and on with lots and lots of words and not very concisely, just like this one. Once we have calculated the signatures of two different texts we can determine their similarity and calculate a likelihood that they were written by the same person.

Automated authorship detection has uses in plagiarism detection, email-filtering, social-science research and as forensic evidence in court cases. Also called authorship attribution, this is a current research field and the state-of-the-art linguistic features are considerably more complicated than the [three] simple features that we will use for our program. But even with our very basic features and simplifications, your program may still be able to make some reasonable predictions about authorship.”

Purpose

This lab is an opportunity for you to practice your skills in 

    string manipulation
    arrays 
    statistics
    file processing   

You will write this lab from scratch and should end up with approximately 60 lines of code. 
Data

mystery0.txt Download mystery0.txt

mystery1.txt Download mystery1.txt

mystery2.txt Download mystery2.txt

mystery3.txt Download mystery3.txt

mystery4.txt Download mystery4.txt

mystery5.txt Download mystery5.txt

Tasks

Part 1:  

Write the code to open a file and print the words in the file.  For now, you may place your files in Project directory, and hardcode the path in your code.  There is no need to store the words anywhere for Part 1.  For Part 1, your output for mystery0.txt should look like this:


The
definition
of
insanity
is
doing 
the
same
thing
over
and
over
and
expecting
different
results

Part 2: 

Comment out your code for Part 1 to print the words. (should be one line)

Store the words and a count of how many times each word appears in the text in parallel arrays.  You may assume that no word will be longer than 35 characters (Supercalifragilisticexpialidocious is only 34 chars), and you may assume that no author will use more than 10,000 words in a text which is pretty close to the estimated writing vocabulary of a strongly literate adult.  Print the count of unique words in the text.  Run this code for both Mystery0 and Mystery1.   For Part 2, your output for mystery0.txt should look like this:

the 2
definition 1
of 1
insanity 1
is 1
doing  1
same 1
thing 1
and 2
over 2
expecting 1
different 1
results 1

Part 3:

Comment out your code for Part 2 to print the count of unique words in the text.

Calculate the following 3 statistics, and print them, each on its own line, labeled and formatted as follows(example below is for Mystery1):

The average word length is: 4.24263

The type token ratio is: 0.0466312

The Hapax Legomana ratio is: 0.0188112

 

The first linguistic feature … is the average word length. This is simply the average number of characters per word...

Type-Token Ratio is the number of different words used in a text divided by the total number of words. It's a measure of how repetitive the vocabulary is. [You must treat uppercase and lowercase and titlecase words as the same word.]

Hapax Legomana Ratio is similar to Type-Token Ratio in that it is a ratio using the total number of words as the denominator. The numerator for the Hapax Legomana Ratio is the number of words occurring exactly once in the text. [You can iterate over your counts array to calculate this number fairly easily.]
