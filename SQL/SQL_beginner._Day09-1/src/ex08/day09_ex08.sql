CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop INT DEFAULT 10)
RETURNS TABLE (fibonacci INTEGER)
AS $$
DECLARE
    fib_1 INT := 0;
    fib_2 INT := 1;
    fib_next INT := 0;
BEGIN
    WHILE fib_next < pstop LOOP
        fibonacci := fib_next;
        fib_next := fib_1 + fib_2;
        fib_1 := fib_2;
        fib_2 := fib_next;
        RETURN NEXT;
    END LOOP;
    RETURN;
END;
$$ LANGUAGE plpgsql;