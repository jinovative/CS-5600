# Multi-Processing Encryption Program

## **File Structure**
`genstrings.c` Generates **random text strings** and writes them to `strings.txt`
`queue.c` / `queue.h` Implements a **queue** to store strings before encryption
`main.c` Reads `strings.txt`, stores strings in a queue, and  to encrypt 100 strings at a time
`encrypt.c` Reads strings, encrypts them using the Polybius cipher, and writes output to `batch_output.txt`
`polybius.c` / `polybius.h` Implements the **Polybius cipher** for encryption and decryption

---

## **How It Works**
1. **Generate Random Strings (`genstrings.c`)**
   - Generates **10,000 random words**.
   - Writes them to `strings.txt`.

2. **Load Strings into Queue (`main.c`)**
   - Reads `strings.txt` and stores each word in a **queue**.

3. **Fork Child Processes to Encrypt (`main.c`)**
   - Processes **100 strings at a time**.
   - Calls `encrypt.c` in a separate process.
   - Writes each batch to a new file (`batch_output_1.txt`, `batch_output_2.txt`, etc.).

4. **Encrypt Strings (`encrypt.c`)**
   - Reads `batch_input.txt`.
   - Encrypts words using the **Polybius cipher** (`polybius.c`).
   - Outputs encrypted strings to `batch_output.txt`.

---

## **How to Compile and Run**

### **1. Compile the Program**
```bash
make
```

#### Compiled List
 **genstrings**
 **main**
 **encrypt**

### **2. Generate Random Strings**
```bash
./genstrings
```

 it would create **strings.txt** with random strings.

### **3. Process Strings and Encrypt
```bash
./main
```

 This reads **strings.txt** and spwns child process to encrypt 100 strings at a time
 After that, writes encypted output to batch_output.txt

### **4. Cleaning UP Files
```bash
make clean
```
