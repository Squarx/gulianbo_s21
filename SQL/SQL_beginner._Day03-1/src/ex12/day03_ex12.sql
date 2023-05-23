WITH ind_range AS (
  SELECT generate_series(
    (SELECT MAX(id) FROM person_order),
    (SELECT MAX(id) + (SELECT MAX(id) FROM person_order) FROM person)) as index
),
    tbl_CTE as (select index as id,
                       id as person_id
                from ind_range join person p
                         on p.id = ind_range.index - ((SELECT MAX(id) FROM person_order)))

-- select * from tbl_CTE;
INSERT INTO person_order(id, person_id, menu_id, order_date)
SELECT tbl_CTE.id,
       tbl_CTE.person_id,
       (SELECT id FROM menu WHERE pizza_name = 'greek pizza'),
       '2022-02-25'
FROM tbl_CTE;

select *
from person_order;

