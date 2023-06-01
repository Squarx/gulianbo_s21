CREATE OR REPLACE VIEW currency_attributes as
select distinct currency_id, c.name, rate_to_usd, c.updated
from balance
         full join currency c on balance.currency_id = c.id
where c.updated = (select max(updated) from currency)
order by rate_to_usd;


CREATE OR REPLACE VIEW user_data as
select u.id                              as user_id,
       COALESCE(name, 'not defined')     as name,
       COALESCE(lastname, 'not defined') as lastname,
       b.type                            as type,
       sum(b.money)                      as volume,
       currency_id
from "user" u
         full join balance b on u.id = b.user_id
group by u.id, b.type, currency_id
order by name desc, lastname, type;


select ud.name as name,
       lastname,
       type,
       volume,
       coalesce(ca.name, 'not defined') as currency_name,
       coalesce(ca.rate_to_usd, 1) as last_rate_to_usd,
       coalesce(ca.rate_to_usd, 1) * volume as total_volume_in_usd
from user_data ud
         full join currency_attributes ca on ud.currency_id = ca.currency_id
order by name desc, lastname, type;

