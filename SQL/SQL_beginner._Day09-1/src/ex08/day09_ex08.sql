CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop INT DEFAULT 10)
RETURNS TABLE (fibonacci INTEGER)
AS $$
DECLARE
    fib1 INT := 0;
    fib2 INT := 1;
    fib3 INT := 0;
BEGIN
    WHILE fib3 < pstop LOOP
        fibonacci := fib3;
        fib3 := fib1 + fib2;
        fib1 := fib2;
        fib2 := fib3;
        RETURN NEXT;
    END LOOP;
END;
$$ LANGUAGE plpgsql;

select * from fnc_fibonacci(100);

select * from fnc_fibonacci();