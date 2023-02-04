import React, { useEffect, useState } from 'react'
import {format,addDays,subDays} from "date-fns";
import Day from './Day';

export default function DayPicker(props) {
    const [daysToShow,setDaysToShow] = useState(9);
    const [days,setDays] = useState([]);

    useEffect(() => {
        const daysTemp = [];

        for(let i = 0; i < daysToShow; i++){
            const day = addDays(subDays(props.selectedDate,daysToShow/2),i);

            daysTemp.push(day);
        }

        setDays(daysTemp);
    },[daysToShow,props.selectedDate])
    
  return (
    <div className='day-picker'>
        {
            days.map(d => 
                (
                <Day key={format(d,'yyyy.MM.dd')} selectedDate={props.selectedDate} date={d} onDateChange={props.onDateChange}/>
            ))
        }
    </div>
  )
}

