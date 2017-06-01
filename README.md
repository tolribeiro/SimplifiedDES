SDES: A simplified version of DES
==============

A simplified version of the famous encryption algorithm Data Encryption Standard DES.

#The encryption process

The simplified DES operates on a 8-bit block of *plaintext* to generate a 8-bit block of *ciphertext*. These types of algorithms are called **block ciphers**. It also uses a 10-bit key, generating two subkeys in the process, used as input for the most delicate part of the algorithm, the *fk function*. <br>

The scheme below shows how the plaintext (input) is manipulated to generate the ciphertext (output).

![encryption](http://toribeiro.com/img/encryption.png "Simplified DES encryption scheme.")


After all these steps, the *output* is the encrypted *input*. 

#The keys generation step

This step only involves single permutations and switching. I strongly believe that if you take a look at the implementation you won't have any problems understanding it.

#The decryption process

DES is a **symmetric cipher**, which means that it uses the same key to *encrypt* and *decrypt* the data. Since my idea was only show the step-by-step encryption process, I decided not to write the function to decrypt it. 

However, you might not have any problems doing it either, because the only thing you'll need to do is the encryption process backwards, i.e.: *output -> IP(output) -> fk(output, k2) -> SW(output) -> fk(output, k1) -> IP Inverse (output) -> input*.

#The implementation in C

Based on the scheme shown above, I implemented the algorithm and came up with the *encrypt* function, that summarizes the encryption process of Simplified DES.  

```c
// ------------------------------------------------
// ---            Encrypt Function   		---
// ------------------------------------------------

void encrypt(char *input, char *key)
{
	initial_permutation(input); // IP
	fk(output, k1); // fk with subkey k1
	switch_halves(output);	// SW
	fk(output, k2); // fk with subkey k2
	initial_permutation_inverse(output); // IP Inverse
}
```

To make it easier to understand, I tried to stick to the names of the variables. The variables *input*, *key* (also the subkeys *k1* and *k2*) and *output* literally mean the same as on the scheme.

#Final Considerations

This algorithm was developed by Professor Edward Schaefer of Santa Clara University. I recommend that you read the appendix *Criptography and Network Security*, explaining the algorithm in details (<a href="http://mercury.webster.edu/aleshunas/COSC%205130/G-SDES.pdf" target="_blank">here</a>). 

Furthermore, take a look at this PDF document (<a href="http://ict.siit.tu.ac.th/~steven/css322y11s2/unprotected/CSS322Y11S2H01-DES-Examples.pdf" target="_blank">here</a>), written by Professor Steven Gordon of Sirindhorn International Institute of Technology, which contains some examples that you may want to verify with my implementation.
