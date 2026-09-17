# **Design Doc for Project 

## **Data Structures**

### **ASTNode**
| Member | Description |
|-|-|
| `int lineno` | The line number of the file this node corresponds to (used for error reporting) |
| `enum NodeType node_type`| Type of node |
| `vector<struct ASTNode*> children` | List of pointers to children nodes |
| `struct STTNode* scope` | The symbol table tree node corresponding to the namescope of this node |
| `struct SemanticData data`| The semantic data of the node |


### **STTNode**
| Member | Description |
|-|-|
| `struct SemanticData* returnType` | Return type for this scope, if the scope is enclosed in a method. |
| `struct STTNode* parent` | Pointer to the symbol table corresponding to the parent namescope |
| `bool classScope` | Flag telling whether this is the class-level scope. |
| `map<char*, SemanticData*, cmp_str>* symTab` | The symbol table, associating identifiers with semantic data. `cmp_str` is a special comparator which checks for string equality. |

To enter an element into the symbol table, we simply add a new mapping from its ID to a copy of its semantic data.

### **SemanticData**
| Member | Description |
|-|-|
| `enum DataType type` | Type of variable (e.g. int, boolean, String, undefined) |
| `vector<struct SemanticData*> formals` | Optional list of pointers to semantic data of formal parameters (if method) |
| `int dimensions` | Number of array dimensions (if array) |
| `union value_t` | The semantic value of the node |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`char* string_value` | Value if string literal or ID |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`boolean boolean_value` | Value if boolean literal |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`int int_value` | Value if integer literal |

## **Algorithm**
As suggested in the slides, after the AST is constructed, it will traverse the AST in two passes in order to construct the symbol table and perform type checking.

### **First Pass**
The first traversal of the AST will begin from the root of the tree.

- At the root AST node, a root symbol table tree (STT) node will be created to represent the class-level namescope. It passes its STT node to the next iteration of the traversal.

- Each time a node is encountered which creates a new namescope (e.g. a method, a compound statement, a control block), a new STT node will be created and set the passed-down previous STT node as its parent.
    - If the node is a method, the STT node's symbol table will be populated with the method's formal parameters

- Each time a variable declaration node is encountered, the program searches the current STT node's and each of its ancestors' symbol tables for that variable's ID 
    - If it already exists, is not a class variable, then the program reports a redeclaration error. If the redeclaration is with a new data type, the symbol table entry's type is updated to undefined.
    - If it does not exist or is a class variable, then an entry is created in the passed-down STT node mapping the node's value (the ID) to its semantic data.
    - This process is repeated if there are additional var declarations following the initial one, with the type being passed down.

- Each time a method declaration node is encountered, the program searches a special method symbol table for that method's ID
    - If it already exists then a redeclaration error is reported. If the return type does not agree with previous declarations, the return type for the method's symbol table entry is updated to undefined.
    - If it does not exist, then an entry is created in the special method symbol table.

- Each time a reference to a variable is encountered (e.g. LeftValue AST node), the program searches the current STT node's and each of its ancestors' symbol tables for that variable's ID 
    - If it exists, then the data type of the node is set to the corresponding data type.
    - If it does not exist, then the data type of the node is set to undefined and a reference-before-declaration error is reported.
    - Furthermore, if the reference is indexed, then the array dimensions of the result will be calculated. If the result has less than 0 dimensions, the program will report a type error and set the result's type to undefined.

### **Second Pass**
The second traversal of the AST will be a post-order traversal starting from the root of the AST. 
- Each time an operation expression node is encountered, the program will check that the operands agree in type with each other (i.e. are the same or either is undefined) and that they are the proper type for the operation. If either of these conditions is false, then the result of the operation will be undefined and a type error will be reported.

- Each time a method call node is encountered, the method symbol table will be searched for a corresponding method definition. 
    - If it exists, the type of the method call is set to the stored return value. The types of the stored parameters will be compared to the arguments provided. If they do not agree, then a type error is reported.
    - If it does not exist, a type error will be reported and the node's type will be set to undefined.

- Each time a variable is assigned a value, whether that happens during its declaration or a statement, the types of the right-hand side and left-hand side will be checked. 
    - If they do not agree, then a type error is reported.

- Each time a control block is encountered, then the type of the condition for that control block will be checked. 
    - If it is not a boolean, a type error is reported.

- Each time an index node is encountered, the children nodes will be checked. 
    - If any child is not an integer or undefined, a type error is reported.

- Each time a return statement node is encountered, the type of the return value will be checked against the stored return value for that node's scope.
    - If they do not match, a type error is reported.

There are more cases, such as for calls to `System.out.println`, `System.out.print`, `Integer.parseInt`, and `.length`, but they very similar to operations and are uninteresting to describe. 
