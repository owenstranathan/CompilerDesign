@.str = private unnamed_addr constant [5 x i8] c"four\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

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

define i32 @main() #0 {
  %len = alloca i32
  %1 = call i32 @strlen( i8* getelementptr inbounds ([5 x i8]* @.str, i32 0, i32 0))
  store i32 %1, i32* %len
  %2 = load i32* %len
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %2)
  ret i32 0
}

declare i32 @printf(i8*, ...) #1
