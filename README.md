# Simple Blockchain Simulation

This section outlines the specification for the C++ files included in this Bitcoin-inspired blockchain simulation.

## 1. `main.cpp`: The Entry Point
- **Responsibilities**:
  - Parse command-line arguments (e.g., block time, block size, number of coins to mine).
  - Initialize the blockchain and mining parameters.
  - Handle the main simulation loop.
  - Provide options for displaying blockchain status or interacting with the system from the command line.
- **Example Tasks**:
  - Load initial configuration.
  - Call functions to add blocks to the chain.
  - Print statistics or summaries.

## 2. `Block.h`: Block Header File
- **Responsibilities**:
  - Define the `Block` class.
  - Declare attributes such as block index, timestamp, hash, previous hash, nonce, transactions, and difficulty target.
  - Provide function declarations for methods like:
    - Generating the block hash.
    - Validating the block's Proof of Work.
    - Setting transactions in the block.

## 3. `Block.cpp`: Block Implementation File
- **Responsibilities**:
  - Implement the methods declared in `Block.h`.
  - Handle hashing of block data.
  - Implement Proof of Work logic (e.g., iterating a nonce until a valid hash is found).
  - Serialize block data for hash generation.
- **Example Methods**:
  ```cpp
  std::string calculateHash();
  void mineBlock(int difficulty);

## 4. `Blockchain.h`: Blockchain Header File
- **Responsibilities**:
  - Define the `Blockchain` class.
  - Declare attributes such as a vector of `Block` objects, difficulty level, mining reward, and unconfirmed transactions.
  - Provide function declarations for:
    - Adding new blocks.
    - Validating the blockchain's integrity.
    - Managing transactions.
    - Retrieving the latest block.

## 5. `Blockchain.cpp`: Blockchain Implementation File
- **Responsibilities**:
  - Implement the methods declared in `Blockchain.h`.
  - Handle block validation (e.g., ensuring hashes match and Proof of Work is valid).
  - Add new blocks to the blockchain.
  - Check the entire blockchain for consistency.
- **Example Methods**:
  ```cpp
  bool isChainValid();
  void addBlock(Block newBlock);

## 6. `Transaction.h`: Transaction Header File
- **Responsibilities**:
  - Define the `Transaction` class.
  - Declare attributes for sender, recipient, amount, and optional metadata (e.g., timestamp).
  - Provide function declarations for serialization and validation.
- **Example Fields**:
  ```cpp
  std::string sender;
  std::string recipient;
  double amount;

## 7. `Transaction.cpp`: Transaction Implementation File
- **Responsibilities**:
  - Implement the methods declared in `Transaction.h`.
  - Serialize transaction data for inclusion in blocks.
  - Validate transactions (e.g., ensure amounts are non-negative).
- **Example Methods**:
  ```cpp
  std::string serialize();
  bool isValid();

## 8. `ProofOfWork.h`: Proof of Work Header File
- **Responsibilities**:
  - Define helper functions or classes for handling Proof of Work.
  - Declare the difficulty calculation logic.
- **Example Methods**:
  ```cpp
  std::string calculateHashWithNonce(std::string data, int nonce);

## 9. `ProofOfWork.cpp`: Proof of Work Implementation File
- **Responsibilities**:
  - Implement the mining algorithm.
  - Perform hash calculations using a cryptographic hashing function (e.g., SHA-256).
  - Adjust the nonce to meet the difficulty target.
- **Example Methods**:
  ```cpp
  void mineBlock(Block &block, int difficulty);

## 10. `Crypto.h`: Cryptographic Utilities Header File
- **Responsibilities**:
  - Define functions for cryptographic hashing (e.g., SHA-256).
- **Example Functions**:
  ```cpp
  std::string sha256(const std::string &input);

## 11. `Crypto.cpp`: Cryptographic Utilities Implementation File
- **Responsibilities**:
  - Implement the cryptographic hashing functions.
  - Use libraries like OpenSSL or a custom SHA-256 implementation.
- **Example Functions**:
  ```cpp
  std::string sha256(const std::string &input);

## 12. `Config.h`: Configuration Header File
- **Responsibilities**:
  - Define global constants and default values (e.g., default block size, mining reward).
  - Provide structure for loading or modifying configurations.

## 13. `Utils.h`: Utility Functions Header File
- **Responsibilities**:
  - Define helper functions for tasks like time formatting or data serialization.
- **Example Functions**:
  ```cpp
  std::string getCurrentTimestamp();
  std::string toHex(const std::string &input);

## 14. `Utils.cpp`: Utility Functions Implementation File
- **Responsibilities**:
  - Implement the helper functions declared in `Utils.h`.
  - Handle non-blockchain-specific logic to keep other files focused.

## 15. Compilation Instructions (Single Command)

- **Responsibilities**:
  - Compile all `.cpp` files in the project and link them into a single executable.
- **Compilation Command**:
  ```bash
  g++ -c main.cpp Block.cpp Blockchain.cpp Transaction.cpp ProofOfWork.cpp Crypto.cpp Utils.cpp -std=c++11 -IC:\Users\josto\vcpkg\installed\x64-windows\include
- **Linking Command**:
  ```bash
  g++ main.o Block.o Blockchain.o Transaction.o ProofOfWork.o Crypto.o Utils.o -o blockchain_sim -LC:\Users\josto\vcpkg\installed\x64-windows\lib -lssl -lcrypto
- **Running the Program**:
  ./blockchain_sim

## 16. Installing OpenSSL (First-time setup)
  1. Install OpenSSL for Windows
  Use vcpkg (Recommended for C++ projects)
  git clone https://github.com/microsoft/vcpkg.git
  .\vcpkg\bootstrap-vcpkg.bat

  2. Install OpenSSL
  .\vcpkg\vcpkg install openssl:x64-windows

  3. Edit the install locations in item 15. to user's local directory -IC:\Users\josto\vcpkg\installed\x64-windows\include



  