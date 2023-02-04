<?php

namespace App\Http\Resources;

use Illuminate\Http\Resources\Json\JsonResource;

class DayMarkResource extends JsonResource
{
    /**
     * Transform the resource into an array.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return array|\Illuminate\Contracts\Support\Arrayable|\JsonSerializable
     */
    public function toArray($request)
    {
        return [
            'habit_id' => $this->habit_id,
            'mark_date' => $this->mark_date,
            'state' => $this->state,
            'value' => $this->value
        ];
    }
}
