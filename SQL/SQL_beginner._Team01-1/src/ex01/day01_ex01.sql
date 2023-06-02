insert into currency
values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency
values (100, 'EUR', 0.79, '2022-01-08 13:29');


CREATE OR REPLACE FUNCTION get_price(id_param bigint, upd_time timestamp) RETURNS numeric AS
$$
DECLARE
    closest_update_date timestamp;
BEGIN
    SELECT max(updated)
    INTO closest_update_date
    FROM currency
    WHERE id = id_param
      AND updated < upd_time;

    IF closest_update_date IS NULL THEN
        SELECT min(updated)
        INTO closest_update_date
        FROM currency
        WHERE id = id_param
          AND updated > upd_time;
    END IF;

    RETURN (select min(rate_to_usd) from currency where id = id_param and updated = closest_update_date);
END;
$$
    LANGUAGE plpgsql;





select coalesce(tmp.name, 'not defined') as name,
       coalesce(tmp.lastname, 'not defined') as lastname,
       currency_attributes.name as currency_name,
       get_price(tmp.currency_id, tmp.updated)  * tmp.money as currency_in_usd

from currency_attributes
    left join (select * from balance b
                   left join "user" on b.user_id = "user".id
                   ) as tmp  on currency_attributes.currency_id = tmp.currency_id
order by name desc, lastname, currency_name;



with test as (
select u.id                              as user_id,
       COALESCE(name, 'not defined')     as name,
       COALESCE(lastname, 'not defined') as lastname,
       b.type                            as type,
       b.money as money,
       currency_id,
       b.updated
from "user" u
         full join balance b on u.id = b.user_id
group by u.id, b.type, currency_id,  b.money, b.updated)
select t.name, t.lastname, ca.name as currency_name,
       get_price(t.currency_id, t.updated) * money as currency_in_usd
from currency_attributes ca join
    test t on t.currency_id  = ca.currency_id
order by name desc, lastname, currency_name;