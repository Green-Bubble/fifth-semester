<?php

namespace App\Http\Requests;

use App\Models\Habit;
use Illuminate\Foundation\Http\FormRequest;
use Illuminate\Support\Facades\Log;
use Illuminate\Validation\Rule;

class UpdateHabitRequest extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     *
     * @return bool
     */
    public function authorize()
    {
        return true;   //Protection against changing not yours habits
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array<string, mixed>
     */
    public function rules()
    {
        return [
            'type' => [
                'required',
                Rule::in(['positiveYN'])
            ],
            'color' => 'required|regex:/^#[0-9a-fA-f]{6}$/',
            'title' => 'required|string|max:255',
            'description' => 'nullable|string',
            'frequency' => [
                'required',
                Rule::in(['everyday'])
            ],
            'startHour' => 'nullable|date_format:H:i',
            'endHour' => 'nullable|date_format:H:i|after:startHour'
        ];
    }
}
