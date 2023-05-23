select id, name,
       Case
           when (age between 10 and 20) then 'interval #1'
           when (age between 21 and 23) then 'interval #2'
           else 'interval #3'
           end as interval_info
from person
order by interval_info