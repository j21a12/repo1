const net = require("net");
const crypto = require("crypto");
const fs = require ('fs');
const path = require('path');

// Creating a function to encrypt string
function encryptString(plaintext, publicKeyFile) {
    const publicKey = fs.readFileSync(publicKeyFile, "utf8");
 
    // publicEncrypt() method with its parameters
    const encrypted = crypto.publicEncrypt(
        publicKey, Buffer.from(plaintext));
 
    return encrypted.toString("base64");
}

// Creating a function to decrypt string
function decryptString(ciphertext, privateKeyFile) {
    const privateKey = fs.readFileSync(privateKeyFile, "utf8");
 
    // privateDecrypt() method with its parameters
    const decrypted = crypto.privateDecrypt(
        {
            key: privateKey,
            passphrase: '',
        },
        Buffer.from(ciphertext, "base64")
    );
 
    return decrypted.toString("utf8");
}

// Defining a text to be encrypted
const plainText = "jafet0!";
/*
// Defining encrypted text
const encrypted = encryptString(plainText, "./public_key0");
 
// Prints plain text
console.log("Plaintext:", plainText);
console.log();
 
// Prints buffer of encrypted content
console.log("Encrypted Text: ", encrypted);
console.log();
 
// Prints buffer of decrypted content
console.log("Decrypted Text: ",
    decryptString(encrypted, "private_key"));

*/
// Defining encrypted text
const encrypted = encryptString(plainText, "./public_key0");
 
// Prints plain text
console.log("Plaintext:", plainText);
console.log();
console.log("Encrypted Text: ", encrypted);
console.log();

const options = {
    port:4000,
    host:'127.0.0.1'
}

const cliente = net.createConnection(options)

cliente.on('connect', ()=>{
    console.log('Coneccted')
   // cliente.write('mensage del cliente')
    cliente.write(encrypted)
    

})

cliente.on('data', (data)=>{
    console.log('server.'+data)
})

cliente.on('error',(err)=>{
    console.log(err.message)
})