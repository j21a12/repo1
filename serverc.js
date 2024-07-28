
const net = require("net");
const os  = require('os');
const crypto = require("crypto");
const fs = require("fs");
const path =require("path");
const host = '192.168.1.111';

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
/*
// Defining a text to be encrypted
const plainText = "jafet!";
 
// Defining encrypted text
const encrypted = encryptString(plainText, "./public_key");
 
// Prints plain text
console.log("Plaintext:", plainText);
console.log();
 
// Prints buffer of encrypted content
console.log("Encrypted Text: ", encrypted);
console.log();
 
// Prints buffer of decrypted content
console.log("Decrypted Text: ",
    decryptString(encrypted, "private_key0")); 
*/
const server = net.createServer()

server.on('connection',(socket)=>{
    socket.on('data',(data)=>{
        console.log('reciv message')
        socket.write('recibido:\n')
       
        const strData = data.toString();
        console.log(`Received: ${strData}`);
        console.log("Decrypted Text: ",
        decryptString(strData, "./private_key0")); 
    })

    socket.on('close',()=>{
        console.log('conextion close')
    })

    socket.on('error',(err)=>{
        console.log(err.message)
    })
})

server.listen(4000,host, ()=>{
    console.log('server start on port:',server.address().port)
})