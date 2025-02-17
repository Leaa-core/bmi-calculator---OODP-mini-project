# bmi-calculator---OODP-mini-project

# BMI Calculator  

## Overview  
The **BMI Calculator** is a simple C program that allows users to calculate their Body Mass Index (BMI), view saved records, and search for specific records by name. The program also stores user input (name, weight, height, and BMI) in a file for later viewing and searching.  

## Features  
- **Calculate BMI**: Users can input their weight and height to calculate their BMI and receive recommendations based on their BMI category.  
- **View BMI Records**: Displays a list of previously saved BMI records from a file.  
- **Search BMI Record**: Allows users to search for a specific BMI record by entering a name.  
- **File Storage**: Saves BMI records to a file (`bmi_records.txt`) for persistent storage.  

## Team Members  
- **Lea Daison** (RA2412703010003)  
- **Vasundara N** (RA2412703010023)  
- **Sesha Priya D** (RA2412707010027)  

## Requirements  
- **C Compiler**: Any C compiler such as GCC should work.  
- **File System**: The program writes BMI records to a text file, so ensure the program has permission to read/write files in the directory.  

## Getting Started  

### Prerequisites  
Make sure you have a C compiler installed. If not, you can download **GCC** for Windows, Linux, or macOS.  

### Compilation and Execution  
1. Clone or download the repository.  
2. Navigate to the project directory.  
3. Open a terminal and compile the program:  
   ```bash
   gcc bmi_calculator.c -o bmi_calculator
   ```  
4. Run the program:  
   ```bash
   ./bmi_calculator
   ```  

### User Instructions  
- Upon running the program, you will be presented with a menu to:  
  1. **Calculate BMI**: Input your name, weight (kg), and height (cm). Your BMI will be calculated, categorized, and saved.  
  2. **View BMI Records**: View a list of all previously saved BMI records.  
  3. **Search Record by Name**: Search for a specific record by entering a name.  
  4. **Exit**: Exit the program.  
- Follow the on-screen prompts for each option.  

## Example  
```
===== BMI Calculator =====  
1. Calculate BMI  
2. View BMI Records  
3. Search Record by Name  
4. Exit  
Enter your choice: 1  

Enter your name: John Doe  
Enter your weight (in kg): 70  
Enter your height (in cm): 175  
Your BMI: 22.86  
Category: Normal weight  
Recommendation: Keep up your healthy lifestyle!  
BMI record saved successfully!  
```

## File Format  
BMI records are stored in the `bmi_records.txt` file in the following format:  
```
<name> <weight> <height> <bmi>
```

Example:  
```
JohnDoe 70.00 1.75 22.86  
```

## License  
This project is open-source and available under the **MIT License**. See the `LICENSE` file for more information.  
