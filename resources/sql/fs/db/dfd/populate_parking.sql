-- *****************************************************************************
-- Copyright 2015-2020 Alexander Barthel alex@littlenavmap.org
--
-- This program is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with this program.  If not, see <http://www.gnu.org/licenses/>.
-- ****************************************************************************/

-- ==================================================================================
-- Fill parking from gates

delete from parking;

insert into parking (airport_id, name, number, has_jetway, lonx, laty)
select
  a.airport_id as airport_id,
  gate_identifier as name,
  -1 as number,
  0 as has_jetway,
  gate_longitude as lonx,
  gate_latitude as laty
from tbl_gate g join airport a on g.airport_identifier = a.ident;

-- Number of gates in airport
update airport set num_parking_gate =
coalesce((select count(1)
from parking p
where p.airport_id = airport.airport_id
group by p.airport_id), 0);
