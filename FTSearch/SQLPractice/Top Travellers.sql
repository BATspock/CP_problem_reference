select U.name, case 
                when sum(R.distance) is null
                then 0
                when sum(R.distance) is not null
                then sum(R.distance)
                end
                as travelled_distance
from Users U
left join Rides R
on U.id = R.user_id
group by R.user_id
order by sum(R.distance) desc, name;
