import React from 'react'
import format from 'date-fns/format'
import { isSameDay, isToday } from 'date-fns'

export default function Day(props) {
  return (
    <button 
    className={`day ${isToday(props.date) ? "today" : ""} ${isSameDay(props.date,props.selectedDate) ? 'selected' : ""}`}
    onClick={() => {props.onDateChange(props.date)}}
    >
        <div>
        {format(props.date,"eee")}
        </div>
        <div>
        {format(props.date,"d")}
        </div>
    </button>
  )
}
