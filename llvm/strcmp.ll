;comparison strings
@string_1 = internal constant [9 x i8] c"string_1\00"
@string_2 = internal constant [9 x i8] c"string_2\00"
@string_3 = internal constant [9 x i8] c"string_1\00"

;printing strings
@one_equals_two = internal constant [21 x i8] c"string_1 == string_2\00"
@one_equals_three = internal constant [21 x i8] c"string_1 == string_3\00"
@true = internal constant [5 x i8] c"true\00"
@false = internal constant [6 x i8] c"false\00"


; Print function declaration
declare i32 @puts(i8*)


define i32
@strlen(i8* %str)
{
    %len = alloca i32 ;allocate a length variable
    store i32 0, i32* %len ;Initialize length as 0
    br label %strlen.condition

strlen.condition:
    ; load the length into a 32bit integer
    %condit_len = load i32* %len
    ; get a pointer to the char offset by length's value
    %condit_offset = getelementptr inbounds i8* %str, i32 %condit_len
    ; load the char at that pointer addr
    %condit_char = load i8* %condit_offset
    ; check for equality with null (0)
    %is_null = icmp eq i8 %condit_char, 0
    ; If null goto end; else goto body
    br i1 %is_null, label %strlen.end, label %strlen.body

strlen.body:
    %body_len = load i32* %len;load the currecnt length
    %incrementedlen = add nsw i32 %body_len, 1 ;increment the length;
    store i32 %incrementedlen, i32* %len ;store new length
    br label %strlen.condition; goto condition

strlen.end:
    ;load length
    %final_len = load i32* %len
    ;return value
    ret i32 %final_len
}


define i1
@strcmp(i8* %str_a, i8* %str_b, i8* %msg)
{
    ; print the message
    call i32 @puts(i8* %msg)
    ; length of string a
    %length_a = call i32 @strlen(i8* %str_a)
    ; length of string b
    %length_b = call i32 @strlen(i8* %str_b)
    ; the reason I don't compare and branch here is because i don't know
    ; how to continue from a branch
    ; an index(offset froms start) counter to iterate over the string
    %idx = alloca i32
    ; tiresomly initialize the idx counter
    store i32 0, i32* %idx
    ; know I'm comparing the lengths of the two strings
    %len_cmp = icmp eq i32 %length_a, %length_b
    ; if they are not equal then branch to false else branch to body
    br i1 %len_cmp, label %strcmp.body, label %strcmp.false

strcmp.body:
    ; load index counter
    %body_indx = load i32* %idx
    ; get pointer to char at index in a;
    %char_ptr_a = getelementptr i8* %str_a, i32 %body_indx
    ; get pointer char at index in b
    %char_ptr_b = getelementptr i8* %str_b, i32 %body_indx
    ;load the chars
    %char_a = load i8* %char_ptr_a
    %char_b = load i8* %char_ptr_b
    ; compare the two
    %char_cmp = icmp eq i8 %char_a, %char_b
    ; if true branch to continue else branch to false
    br i1 %char_cmp, label %strcmp.continue, label %strcmp.false

strcmp.continue:
    ; load the index
    %cont_indx = load i32* %idx
    ; increment the index
    %inc_index = add i32 %cont_indx, 1
    ; store the incremented index back
    store i32 %inc_index, i32* %idx
    ; check for inbounds
    %inbounds_cmp = icmp sle i32 %inc_index, %length_a
    ; if still in bounds return to body and check the next char
    ; else the strings are equal and branch to true
    br i1 %inbounds_cmp, label %strcmp.body, label %strcmp.true

strcmp.false:
    ; print "false"
    call i32 @puts(i8* getelementptr inbounds ([6 x i8]* @false, i32 0, i32 0))
    ; return false
    ret i1 0

strcmp.true:
    ; print "true"
    call i32 @puts(i8* getelementptr inbounds ([5 x i8]* @true, i32 0, i32 0))
    ; return true
    ret i1 1

}

define i32
@main()
{
    ; get pointers to the global strings
    %str_1 = getelementptr inbounds [9 x i8]* @string_1, i32 0, i32 0
    %str_2 = getelementptr inbounds [9 x i8]* @string_2, i32 0, i32 0
    %str_3 = getelementptr inbounds [9 x i8]* @string_3, i32 0, i32 0

    call i1 @strcmp(i8* %str_1, i8* %str_2,
        i8* getelementptr inbounds ([21 x i8]* @one_equals_two, i32 0, i32 0))

    call i1 @strcmp(i8* %str_1, i8* %str_3,
        i8* getelementptr inbounds ([21 x i8]* @one_equals_three, i32 0, i32 0))

    ret i32 1
}
