WITH adress_n_ages as (SELECT address,
                              ROUND(MAX(age::NUMERIC) - MIN(age::NUMERIC) / MAX(age::NUMERIC), 2) AS formula,
                              ROUND(AVG(age), 2)                                                  AS average
                       FROM person
                       GROUP BY address
                       ORDER BY address)
SELECT address,
       formula,
       average,
       CASE
           WHEN formula > average THEN true
           ELSE false
           END AS comparison
FROM adress_n_ages;
