pragma solidity >= 0.7.0;

contract Bank {
    // Mapping to store user account balances
    mapping (address => uint) public user_account;
    
    // Mapping to track whether a user account exists
    mapping (address => bool) public user_exist;
    
    // Function to create an account
    function create_account() public payable returns (string memory) {
        // Check if the account already exists
        require(user_exist[msg.sender] == false, "Account already created!");
        
        // Set the account balance for the user to the value sent with this transaction
        user_account[msg.sender] = msg.value;
        
        // Mark the account as created
        user_exist[msg.sender] = true;
        
        return "Account created";
    }
    
    // Function to deposit funds into the account
    function deposit(uint amount) public payable returns (string memory) {
        // Check if the account exists
        require(user_exist[msg.sender] == true, "Account not created");
        
        // Check if the deposited amount is greater than 0
        require(amount > 0, "Amount must be greater than 0");
        
        // Add the deposited amount to the user's account balance
        user_account[msg.sender] += amount;
        
        return "Amount deposited successfully";
    }
    
    // Function to withdraw funds from the account
    function withdraw(uint amount) public payable returns (string memory) {
        // Check if the account exists
        require(user_exist[msg.sender] == true, "Account not created");
        
        // Check if the withdrawal amount is greater than 0
        require(amount > 0, "Amount should be greater than 0");
        
        // Check if the withdrawal amount is not greater than the account balance
        require(user_account[msg.sender] >= amount, "Amount is greater than balance");
        
        // Subtract the withdrawal amount from the user's account balance
        user_account[msg.sender] -= amount;
        
        return "Amount withdrawn successfully";
    }
    
    // Function to view the account balance
    function show_balance() public view returns (uint) {
        return user_account[msg.sender];
    }
    
    // Function to check if the account exists
    function account_exists() public view returns (bool) {
        return user_exist[msg.sender];
    }
}
