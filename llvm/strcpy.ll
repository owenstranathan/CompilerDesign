@orig_str = internal constant [29 x i8] c"This is a string for copying\00"
@copy_str = internal global [29 x i8] zeroinitializer

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


define i32
@strcpy(i8* %src, i8* %dest)
{
    ;get length of string
    %length = call i32 @strlen(i8* %src)
    ; index counter
    %idx = alloca i32
    ;init offset
    store i32 0, i32* %idx
    ;goto condition
    br label %strcpy.condition

strcpy.condition:
    ; get the index
    %condit_idx = load i32* %idx
    ; compare index to length
    %condit_cmp = icmp slt i32 %condit_idx, %length
    ; if still less than length goto body
    br i1 %condit_cmp, label %strcpy.body, label %strcpy.end

strcpy.body:
    ; load index counter
    %body_idx = load i32* %idx
    ; get pointer to the character at the index
    %src_char_ptr = getelementptr inbounds i8* %src, i32 %body_idx
    ; Load character from pointer to source
    %src_char = load i8* %src_char_ptr
    ; Get a pointer to the character at index in dest
    %dest_char_ptr = getelementptr inbounds i8* %dest, i32 %body_idx
    ; Set the character at dest
    store i8 %src_char, i8* %dest_char_ptr
    ;increment index counter
    %inc_idx = add i32 %body_idx, 1
    store i32 %inc_idx, i32* %idx
    ;Goto conidt
    br label %strcpy.condition

strcpy.end:
    ;load offset
    %end_idx = load i32* %idx
    ; increment
    %end_inc_idx = add i32 %end_idx, 1
    ;get a pointer to the end of the dest string to null terminate the string
    %end_ptr = getelementptr inbounds i8* %dest, i32 %end_idx
    ; null terminate the string
    store i8 0, i8* %end_ptr
    ret i32 %length
}

define
i32 @main()
{
    %src_string = getelementptr inbounds [29 x i8]* @orig_str, i32 0, i32 0
    %dest_string = getelementptr inbounds [29 x i8]* @copy_str, i32 0, i32 0
    %result = call i32 @strcpy(i8* %src_string, i8* %dest_string)
    call i32 @puts(i8* %src_string)
    call i32 @puts(i8* %dest_string)
    ret i32 0
}
