with selected_dates as (select visit_date
                        from person_visits
                        where person_id = 1
                           OR person_id = 2),
     date_range as (select generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day'::interval) as visit_date)
select to_char(dr.visit_date, 'YYYY-MM-DD') as missing_date
from date_range dr
         left join selected_dates sd on sd.visit_date = dr.visit_date
where sd.visit_date is null
order by dr.visit_date;