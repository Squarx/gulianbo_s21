select  distinct person_visits.visit_date as missing_date from person_visits left join
(select visit_date
from person_visits
where person_id = 1
   or person_id = 2) as tmp
on tmp.visit_date= person_visits.visit_date
where tmp.visit_date is null
order by person_visits.visit_date;