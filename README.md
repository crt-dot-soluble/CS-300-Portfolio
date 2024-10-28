### 1. **What was the problem you were solving in the projects for this course?**

In the projects for this course, the problem I was solving involved creating a **course advising assistance program** for academic advisors at ABCU. The program needed to efficiently load, store, and manage course data, allowing users to view a list of courses, retrieve specific course information, and display prerequisites. The main challenges were:
- Loading course data from a file into an appropriate data structure.
- Providing a user-friendly menu for interacting with the data.
- Sorting and retrieving course information efficiently.

### 2. **How did you approach the problem? Consider why data structures are important to understand.**

I approached the problem by first analyzing the requirements and then selecting the most appropriate data structures to handle the operations efficiently. Data structures are crucial because they determine how efficiently data can be stored, retrieved, and manipulated. For example:
- I considered using a **hash table** (unordered_map in C++) to store course data because it allows for **constant-time** (O(1)) lookups, which is ideal for quickly retrieving course details.
- Sorting the courses required a data structure that could easily support sorting, so I used a combination of the hash table with a vector to store course numbers, then sorted the vector for alphanumeric display.

Understanding data structures helped me choose the most efficient ways to store and manage data, ensuring the program met performance requirements, especially as the dataset grows.

### 3. **How did you overcome any roadblocks you encountered while going through the activities or project?**

Some of the roadblocks I encountered included:
- **File parsing issues** when reading and interpreting CSV data, especially handling cases where courses had varying numbers of prerequisites.
- Ensuring the **correct sorting** of course data in alphanumeric order.
- Handling **invalid user input** gracefully, such as when a user entered a course that didn’t exist or selected an invalid menu option.

I overcame these roadblocks by:
- Implementing a **robust file parsing function** (using the `split` function) to correctly tokenize the input data and handle missing or incomplete fields.
- Using the **`sort` function** in C++ to order course numbers alphanumerically, ensuring the courses were displayed correctly.
- Adding **input validation** and error handling to guide the user and prevent crashes when invalid input was encountered.

### 4. **How has your work on this project expanded your approach to designing software and developing programs?**

This project expanded my approach to software design by emphasizing the importance of:
- **Modular programming**: By breaking the program into smaller, reusable functions (e.g., `loadCourses`, `printCourseList`, `printCourse`), I made the code more organized and easier to maintain.
- **Scalability**: Choosing the right data structures (hash tables, vectors) was not only about solving the immediate problem but also about making sure the program could handle larger datasets efficiently in the future.
- **User experience**: Designing an intuitive and error-tolerant menu system made me more aware of how users interact with programs and how vital it is to anticipate and handle various inputs gracefully.

The project also reinforced the idea that **good planning and design** (like selecting the correct data structures) can significantly simplify the implementation process later on.

### 5. **How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**

This project has evolved my programming style by reinforcing several best practices:
- **Commenting and readability**: I ensured that the code was well-commented and used clear, descriptive variable names to make it easier for others (and myself) to understand the code in the future.
- **Maintainability**: By using modular functions and separating concerns, I made the program more maintainable. For example, if the file parsing logic needs to change, I can modify the `loadCourses` function without affecting other parts of the program.
- **Adaptability**: The program is designed to be adaptable to changes in the course data structure or user interface. If new features are needed, such as handling more course attributes, the existing code structure can be easily extended without significant rewrites.

Overall, this project taught me the importance of writing clean, modular, and efficient code that is not only functional but also easy to maintain and adapt for future requirements.
