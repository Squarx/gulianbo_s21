DROP VIEW IF EXISTS v_generated_dates;
CREATE OR REPLACE VIEW v_generated_dates AS
SELECT TO_CHAR(generate_series, 'YYYY-MM-DD')::DATE AS generated_date
FROM generate_series('2022-01-01'::DATE, '2022-01-31'::DATE, '1 day'::INTERVAL);

select * from v_generated_dates;

