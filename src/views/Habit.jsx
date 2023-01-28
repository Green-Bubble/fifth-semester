import React, { useState } from 'react'
import Icon from '@mdi/react';
import { mdiClose , mdiMinus, mdiCheck} from '@mdi/js';

export default function Habit(props) {
    const [marked,setMarked] = useState(null);

    return (
    <div className='habit'>
        <span 
        style={{color: props.habit.color}}
        onClick={() => {props.onHabitClick(props.habit)}}>
            {props.habit.title}
        </span>
        <span 
            className='habit-state'
            onClick={() => {setMarked(!marked)}}
        >
            {marked === null && 
                <Icon path={mdiMinus} size={1} />
            }
            {marked === true &&
                <Icon path={mdiCheck} size={1} />
            }
            {marked === false &&
                <Icon path={mdiClose} size={1} />
            }
        </span>
    </div>
    )
}
