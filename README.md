# DataBaseTest

A small C++ console program that exercises SQLite's C API. The default run opens `test.db` in the working directory, creates an `event` table, inserts a sample event and prints the rows. Each event has an ID, title, category, state and two time fields.

## Run the example on macOS

With the Xcode Command Line Tools installed, run these commands from the repository root. The temporary directory gives the demo its own database. The table setup can drop an existing `event` table.

```sh
demo_dir=$(mktemp -d)
clang++ -std=c++11 DataBaseTest/*.cpp -lsqlite3 -o "$demo_dir/db-demo"
(cd "$demo_dir" && ./db-demo)
sqlite3 "$demo_dir/test.db" '.schema event'
```

You can also open [DataBaseTest.xcodeproj](DataBaseTest.xcodeproj) in Xcode. For the command-line build, Clang may warn about the cleanup function deleting an incomplete `sqlite3` type.

## Follow the run

1. [main.cpp](DataBaseTest/main.cpp) selects `Run_Default_Values_Test`.
2. [Test_option.cpp](DataBaseTest/Test_option.cpp) sequences the create, insert and display operations. It also contains the interactive variants.
3. [Datebase_Test_API.cpp](DataBaseTest/Datebase_Test_API.cpp) supplies the example SQL. [Database_controll_API.cpp](DataBaseTest/Database_controll_API.cpp) opens the database, executes the statements and handles query results.
