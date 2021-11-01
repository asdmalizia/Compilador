## Setup
### 1. Build
In project folder, execute:

`make`

### 2. Run
After building the application, run in project folder:

`compilador [SCRIPT_NAME] -o [OUTPUT_FILE_NAME]`

There are a test example in the file "teste_lexico":

`compilador teste_lexico -o output`

Then, the output to the corresponding code would be:


<table>
<tr>
<th>Coding example </th>
<th>Lexical tokens</th>
<th>Syntactical output</th>
</tr>
<tr>
<td>

```C++
function factorial(n: integer) : integer {
	var result: integer;

	while(result>0){
		result = result * (result - 1);
	}

	return result;
}
```

</td>
<td>

```txt
8 
48 ID id=0 
27 
48 ID id=1 
19 
10 
28 
19 
10 
25 
16 
48 ID id=2 
19 
10 
20 
17 
27 
48 ID id=2 
32 
46 INT id=0 0 
28 
25 
48 ID id=2 
22 
48 ID id=2 
41 
27 
48 ID id=2 
39 
46 INT id=1 1 
28 
20 
26 
18 
48 ID id=2 
20 
26 
50 
```

</td>
<td>

```txt

BEGIN_FUNC 0 1 1
L1
	LOAD_VAR 0
	LOAD_CONST 0
	GT
	TJMP_FW L0
	LOAD_VAR 0
	LOAD_VAR 0
	LOAD_CONST 1
	SUB
	MUL
	STORE_VAR 0
	JMP_BW L1
L0
	LOAD_VAR 0
	RET
END_FUNC


```
</td>
</tr>
</table>

### 3. Clean
Clean the generated files executing:

`make clean`
