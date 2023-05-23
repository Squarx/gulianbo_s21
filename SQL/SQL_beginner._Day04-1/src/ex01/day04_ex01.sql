with united_mpa_CTE as (SELECT *
                        FROM v_persons_female
                        union all
                        SELECT *
                        FROM v_persons_male)
SELECT name FROM united_mpa_CTE
ORDER BY name;

