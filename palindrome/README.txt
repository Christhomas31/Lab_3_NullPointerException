The first change we made was freeing the result from str_reverse. We had to free the address in palindrome after it was returned from a function. The address of the result was held
in the variable 'rev' so this memory leak was solved with free(rev);. The other two memory leaks came from the dynamically allocated memory for the return strings in palindrome.
In order to fix this, in the test file we assigned the address of the result in a variable (pal), then after the variable was used, it was deallocated(with free(pal);).
