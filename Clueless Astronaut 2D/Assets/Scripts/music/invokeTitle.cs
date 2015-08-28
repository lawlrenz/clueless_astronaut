using UnityEngine;
using System.Collections;

public class invokeTitle : MonoBehaviour {

	public AudioClip ac;
	public float volume;

	// Use this for initialization
	void Start () {
		GameObject go = GameObject.Find ("bgMusicHandler");
		if (go.GetComponent<AudioSource> ().clip != ac) {
			go.GetComponent<AudioSource> ().clip = ac;
			go.GetComponent<AudioSource> ().volume = volume;
			go.GetComponent<AudioSource> ().loop = true;
			go.GetComponent<AudioSource> ().Play ();
		}
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
