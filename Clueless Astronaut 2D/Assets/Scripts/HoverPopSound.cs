using UnityEngine;
using System.Collections;

public class HoverPopSound : MonoBehaviour {

	public AudioSource as_hover;

	// Use this for initialization
	void Start () {
		AudioClip hover_sound;
		hover_sound = (AudioClip)Resources.Load ("mouthpop2");
		as_hover.clip = hover_sound;
		as_hover.loop = false;
		as_hover.volume = 0.1f;


	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnMouseEnter(){
		as_hover.PlayOneShot(as_hover.clip);
	}
}
