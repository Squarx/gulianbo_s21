DROP FUNCTION IF EXISTS func_minimum;
CREATE OR REPLACE FUNCTION func_minimum (VARIADIC arr numeric[])
RETURNS numeric AS
$$
BEGIN
    RETURN (SELECT min(value) FROM unnest(arr) AS value);
END;
$$ LANGUAGE plpgsql;

