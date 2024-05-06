# San-Ynon-ex4
Program Description:
For this milestone we created two distinct programs, a client and server. The client can send the server vectors and the server will classify them using the KNN algorithm.
The communication between them goes as follows - The server offers the client a menu of options:
1. upload an unclassified csv data file
2. algorithm settings
3. classify data
4. display results
5. download results
6. exit

from here the client can either view the algorithm settings or upload the training data and testing data, Else will recieve an error
and get the menu again. After uploading the files the client can use the rest of the menu. In order to get the classified results, the client must first
classify data and then they can either print or download the results.
the server uses the KNN algorithm with various distance metrics, in order to classify data.
The server supports multiple clients using threads.
To upload data, enter the path to the local data files. To download the results, enter press 5 and enter a path to the file you would like to download the data to. Any
data already stored in the file will be overwritten.


To start the server provide the following arguments:
1. port - the port number to listen to

For the client side, the arguments needed to run are:
1. ip - the address of the server
2. port - the port number

Once the connection has been established the user on the client side can start using the server.
To quit and close the client, enter `8`.

If an invalid input has been entered in either of the data files, an error message
will be printed to the screen.

**Valid inputs:**

Valid vectors: numbers (positive, negative, decimal, scientific notation). Each component of the vector must 
be within the bounds of representation of double, including the input of numbers in scientific notation (such as 1e-10). 
The vector you want to classify must be of equal length as the vectors you are using to classify it.

Valid distance: The distances currently supported by the KNN algorithm on the server side are:
- AUC
- MAN
- CHB
- CAN
- MIN

Any other input is handled as invalid.

Valid K: A valid k, i.e. number of neighbours must be greater than zero and no greater than the total number of
classified data points provided to the algorithm.

## Compilation and Run Instructions
Download repository. Using the terminal, navigate to project directory and run command `make`. This will generate
two files, client and server. To run the programs, open two terminals and on one enter `./server port`, on the other
enter `./client ip port`. You can then use the programs as described above.
