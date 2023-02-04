<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class DayMark extends Model
{
    use HasFactory;

    public function habit(){
        return $this->belongsTo(Habit::class);
    }

    protected $fillable = [
        'habit_id',
        'mark_date',
        'state',
        'value'
    ];

    protected $casts = [
        'mark_date' => 'datetime',
    ];
}
