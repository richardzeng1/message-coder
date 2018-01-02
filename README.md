# message-coder
A message encoder and decoder based on a secret algorithm

![University of Toronto](https://upload.wikimedia.org/wikipedia/en/thumb/9/9a/UofT_Logo.svg/1280px-UofT_Logo.svg.png)


#### **Table of Contents**
1. Description
2. Setup
3. Usage


### **Description**
This is an assignment from the University of Toronto's Computer Science program. It is the first assignment from the course
CSC209. The assignment was to compose a secret message using a piece of text as a key. More specifically, for each line of 
coded message, it would correspond to a series of characters from the text. Once the characters from the text at the specified
locations were constructed into a string, a message would appear. This means that only one source of text would produce a
valid message. 

The coded message was comprised of 3 space separated numbers. The first is the line number, the second is the starting
character position in the line and the third is the number of characters. The line numbers and character positions start at 0
and there cannot be any size of 0.

The two components of the assignment were:

1. Decoding a message

      Given a coded message, output the decoded message to standard output.
      
2. Encoding a message

      Given a message, produce a code that would translate to the message. There are a few conditions:
      
          1. A chunk size must be passed in as an argument and all message sizes will be of this size.
          
             The exception is when the number of characters does not divide evenly into the chunk size, then, the last
             
             bit of characters can be less than the specified size.
             
          2. One line can only contain one chunk of the message.
          
          3. If the message cannot be encoded, an error message is printed to stderr and program will return with a value
          
                 of 1.
                 
Final Mark: 98.32%

### **Setup**


## **Usage**

